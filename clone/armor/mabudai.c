// Code of ShenZhou
// mabudai.c �鲼��

inherit ITEM;

void create()
{
	set_name("�鲼��", ({ "budai", "dai", "bag" }));
	set_weight(500);
	set_max_encumbrance(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ���鲼֯�ɵĴ��ӣ��������װ������\n");
		set("value", 50);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/mabudai.c");
//***** END OF ADDING *****
		set("material", "cloth");
	}
}

int is_container() { return 1; }
