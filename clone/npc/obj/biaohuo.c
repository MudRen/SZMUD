// Code of ShenZhou
// clone/npc/obj/biaohuo.c
// sdong, 12/12/98
#include <ansi.h>

inherit ITEM;

void create()
{
		  set_name("�ڻ�", ({ "biao huo", "huo" }));
		  set_weight(10000);
		  set("no_steal", "�ⶫ������͵��\n");
		  set("long", "����һ������Ͳ�����װ�Ķ�������֪����װ��Щʲô��\n");
		  set("material", "steel");
		  set("regidity", 100000000);
		  set("unit", "��");
		  set("value", 10000000);
		  setup();
}

