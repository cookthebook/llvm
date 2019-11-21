#include "llvm/Support/Debug.h"
#include "ARM.h"
#include "ARMBaseInstrInfo.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
using namespace llvm;

namespace {
  struct uXOMLoadStorePass : public MachineFunctionPass {
    static char ID;
    uXOMLoadStorePass() : MachineFunctionPass(ID) {}

    bool runOnMachineFunction(MachineFunction &Fn) override;

    StringRef getPassName() const override {
      return "uXOM Load/Store pass";
    }

  private:
    bool replaceLoadStore(MachineBasicBlock &MBB);
  };
  char uXOMLoadStorePass::ID = 0;
}

bool
uXOMLoadStorePass::replaceLoadStore(MachineBasicBlock &MBB) {
  MachineBasicBlock::reverse_iterator MII = MBB.rbegin(), E = MBB.rend();
  while (MII != E) {
    MachineInstr *MI = &*MII++;
    DEBUG_WITH_TYPE("uxom", dbgs() << "Current OpCode: " << MI->getOpcode() << "\n");
  }
  
  return false;
}

bool
uXOMLoadStorePass::runOnMachineFunction(MachineFunction &Fn) {
  bool Modified = false;
  for (MachineBasicBlock &MBB : Fn) {
    Modified |= replaceLoadStore(MBB);
  }
  return true;
}

FunctionPass *llvm::createuXOMLoadStorePass() {
  return new uXOMLoadStorePass();
}
