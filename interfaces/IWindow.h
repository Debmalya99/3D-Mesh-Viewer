#ifndef __IWINDOW_H__
#define __IWINDOW_H__

#include "../config.h"
#include "../classes/InputManager.h"

class IWindow
{
protected:
	bool mRunning; // Set this to true in derived's constructor
public:
	InputManager* inputSystem;	// Set its value in backend's constructor
	virtual void Init() = 0;
	virtual void HandleEvents() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void PreProcess() = 0;
	virtual bool isRunning(){return mRunning;}
	virtual void swapBuffers() = 0;
	virtual void CleanUp() = 0;
};

#endif
