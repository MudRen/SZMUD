// Code of ShenZhou
//Ȩ�����ƣ����ķ���400 lv�����ڳ������֣�������������ɲ���ƽ�� //by maco
// fojing20.c

inherit ITEM;

string* titles = ({
//	"������",
//	"άĦ��",
//	"������",
//	"���Ͼ�",
	"�����پ�",
	"������;�",
	"������",
	"��վ�",
	"�����۶��ľ�",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��𾭡�\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	4000000,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	400	// the maximum level you can learn
		]) );
	}
}
