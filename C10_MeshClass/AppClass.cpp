#include "AppClass.h"
void Application::InitVariables(void)
{
	//Make MyMesh object
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(2.0f, C_BLACK);
	m_pMesh1 = new MyMesh();
	m_pMesh1->GenerateCube(2.0f, C_BLACK);
	m_pMesh2 = new MyMesh();
	m_pMesh2->GenerateCube(2.0f, C_BLACK);
	m_pMesh3 = new MyMesh();
	m_pMesh3->GenerateCube(2.0f, C_BLACK);
	m_pMesh4 = new MyMesh();
	m_pMesh4->GenerateCube(2.0f, C_BLACK);
	m_pMesh5 = new MyMesh();
	m_pMesh5->GenerateCube(2.0f, C_BLACK);
	m_pMesh6 = new MyMesh();
	m_pMesh6->GenerateCube(2.0f, C_BLACK);

	//Make MyMesh object
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	static float fDisp = 0.0f; //static only initializes once
	fDisp += 0.01f;
	matrix4 m4Space = glm::translate(vector3(fDisp, 1.0f, 0.0f));
	matrix4 m4Translation = m4Space * glm::translate(vector3(0.0f, 0.0f, 0.0f));
	matrix4 m4Translation1 = m4Space * glm::translate(vector3(2.0f, 0.0f, 0.0f));
	matrix4 m4Translation2 = m4Space * glm::translate(vector3(4.0f, 0.0f, 0.0f));
	matrix4 m4Translation3 = m4Space * glm::translate(vector3(6.0f, 0.0f, 0.0f));
	matrix4 m4Translation4 = m4Space * glm::translate(vector3(8.0f, 0.0f, 0.0f));
	matrix4 m4Translation5 = m4Space * glm::translate(vector3(10.0f, 0.0f, 0.0f));
	matrix4 m4Translation6 = m4Space * glm::translate(vector3(12.0f, 0.0f, 0.0f));

	m_pMesh->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation);
	m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation1);
	m_pMesh2->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation2);
	m_pMesh3->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation3);
	m_pMesh4->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation4);
	m_pMesh5->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation5);
	m_pMesh6->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Translation6);
		
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}
	SafeDelete(m_pMesh1);
	//release GUI
	ShutdownGUI();
}