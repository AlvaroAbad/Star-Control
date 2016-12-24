#include "..\include\behaviouraltrees.h"
#include "../include/selectornode.h"
#include "../include/sequencenode.h"
#include "../tasks/include/checkthreattask.h"
#include "../tasks/include/calcrotationtask.h"
#include "../tasks/include/checkenergytask.h"
#include "../tasks/include/checklifetask.h"
#include "../tasks/include/checkalignmenttask.h"
#include "../tasks/include/checkrangetask.h"
#include "../tasks/include/intercepttask.h"
SimpleAIBehaviouralTree::SimpleAIBehaviouralTree(Entity * Owner)
{

	root = new SelectorNode();
	/*Avoid Threat*/
	SequenceNode * sequence = new SequenceNode();
	root->AddNode(sequence);
	sequence->AddNode(new CheckThreatTask(Owner, &context))->AddNode(new CalculateRotationTask(Owner, &context));
	root->AddNode(sequence);
	/*Persue Fire*/
	sequence = new SequenceNode();
	root->AddNode(sequence);
	sequence->AddNode(new CheckEnergyTask(Owner, &context))->AddNode(new CheckLifeTask(Owner, &context));

	SelectorNode * selector = new SelectorNode();
	sequence->AddNode(selector);
	
	/*Fire*/
	sequence = new SequenceNode();
	selector->AddNode(sequence);
	sequence->AddNode(new CheckAlignmentTask(Owner, &context))->AddNode(new CheckRangeTask(Owner, &context));
	/*persue*/
	sequence = new SequenceNode();
	selector->AddNode(sequence);
	sequence->AddNode(new InterceptTask(Owner, &context));
}

void SimpleAIBehaviouralTree::Run()
{
	if (!root->initialized()) {
		root->Init();
	}
	root->Run();
}

DroneAIBehaviouralTree::DroneAIBehaviouralTree(Entity * Owner) {
	root = new SelectorNode();

	/*Fire*/
	SequenceNode * sequence = new SequenceNode();
	root->AddNode(sequence);
	sequence->AddNode(new CheckAlignmentTask(Owner, &context))->AddNode(new CheckRangeTask(Owner, &context));
	/*persue*/
	sequence = new SequenceNode();
	root->AddNode(sequence);
	sequence->AddNode(new InterceptTask(Owner, &context));
}

void DroneAIBehaviouralTree::Run() {
	if (!root->initialized()) {
		root->Init();
	}
	root->Run();
}
