// Code of ShenZhou

inherit ITEM;

void create()
{
	set_name( "����ɨҶ���ķ�", ({ "xin fa","book", "fa" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "
һ�ű�ֽ��������������д����ӬͷС�����Ա��ƺ���Щ��ע��\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"kick",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 10, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
		]) );
	}
}
