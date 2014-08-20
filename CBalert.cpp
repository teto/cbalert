#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "CBalert.h"
#include <logmanager.h>
// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<CBalert> reg(_T("CBalert"));
}



// constructor
CBalert::CBalert()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("CBalert.zip")))
    {
        NotifyMissingFile(_T("CBalert.zip"));
    }
}

// destructor
CBalert::~CBalert()
{
}


void CBalert::Alert(CodeBlocksEvent& event)
{
    wxBell();
}


// TODO on execution, run
// http://wiki.codeblocks.org/index.php?title=Code::Blocks_SDK_events
void CBalert::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
    cbEventFunctor<CBalert, CodeBlocksEvent> *functor = new cbEventFunctor<CBalert, CodeBlocksEvent>(this, &CBalert::Alert);
//Manager::Get()->RegisterEventSink(cbEVT_DEBUGGER_PAUSED, functor);
//Manager::Get()->RegisterEventSink(cbEVT_DEBUGGER_FINISHED, functor);
Manager::Get()->RegisterEventSink(cbEVT_COMPILER_FINISHED, functor);



}

void CBalert::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...

    // Note: on release codeblocks automatically unsubscribes to events
}
