#include "mudos_interger.h"
inherit NPC;

void create()
{
  set_name("��", ({"cha",}));
}

void init()
{
        add_action("do_print", "print");
}

int do_print()
{
        int i;
        i = 900000000 * 1000000000;
        write("testing" + i + "\n");
        return 1;
}
