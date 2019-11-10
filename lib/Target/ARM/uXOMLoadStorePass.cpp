#include "llvm/CodeGen/MachineFunctionPass.h"
using namespace llvm;

namespace {
  struct uXOMLoadStorePass : MachineFuncionPass {
    static char ID;
    uXOMLoadStorePass() : MachineFunctionPass(ID) {}

    StringRef getPassName() const override {
      return "uXOM Load/Store pass";
    }

  private:
    void replaceLoadStore(MachineBasicBlock &MBB);
  }
}

void
uXOMLoadStorePass::replaceLoadStore(MachineBasicBlock &MBB) {
  MachineBasicBlock::reverse_iterator MII = MBB.rbegin(), E = MBB.rend();
  while (MII != E) {
    MachineInstr *MI = &*MII++;
    
    switch (MI->getOpcode()) {
    case ARM::LDR:
      break;
    case ARM::LDRH:
      break;
    case ARM::LDRSH:
      break;
    case ARM::LDRB:
      break;
    case ARM::LDRSB:
      break;
    case ARM::STR:
      break;
    case ARM::STRH:
      break;
    case ARM::STRB:
      break;
    default:
      break;
    }
  }
}
