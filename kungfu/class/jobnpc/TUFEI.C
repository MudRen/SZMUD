#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "tufei"}));
        set("gender", "����");
        set("age", random(10) + 25);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "����ͷ��\n");
        setup();
        return 0;
}
