// Code of ShenZhou
// ׯ��
inherit ITEM;
inherit F_UNIQUE;

void init();

void create()
{
	set_name("��ׯ�ӡ����", ({"zhujian", "bamboo" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
		else {
		set("value", 100);
		set("unit", "��");
		set("huiwen",1);
		set("long", 
		"һ����򣬼���Ϳ�˺��ᣬ������������������������д�����ܵĺ��֡�\n"
		"ͷһ���ǡ���ڤ���㣬����Ϊ���������ȥ����һƪƪ���ǡ�ׯ�ӡ���\n"
		"ֻ���м���һƬ��Щ��ͬ��ÿ�����Լ�������Ȧ�㣬��д�ż����Ż��ġ�\n");
		set("material", "bamboo");
	}
	setup();
	::create();
}

void init()
{
	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 
	int neili_lost;

	if (arg== "zhujian" || arg== "bamboo") {
		write("ׯ�ӽ��˴��˳�죬���书ȫ����ɡ�\n");
		return 1;
	}

	return 0;
}
