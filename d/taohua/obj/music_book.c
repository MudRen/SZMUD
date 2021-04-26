// Code of ShenZhou
//music book

inherit ITEM;


string* names = ({
        "���ָ�����Ҫ�⡷",
        "������Ҫ¼��",
        "���ػ����ס�",
        "������ʮ��ʫ�ס�",
});
string* longs = ({
        "������¼���ƴ��⾤׫����������������������ɣ����о�����κ������������\n�൱�вο���ֵ��\n",
        "�ƴ�����ѧ�������Ա�����ǿ����������������������֮���������������ص㡣\n",
        "�ػ�ʯ���ղص��������ﳭ¼�����ж�ʮ�������ס��������ֳ�Ϊ�����ְ����ס���\n�����ж�ʮ������������з��ź����ֱ�ʾ���ߺͽ��ࡣ\n",
        "�δ�ʫ���׼�����ʳ���ʫ�����������ַ���������\n",
});


void create()
{
	int num = random(4);

	set_name( names[num], ({ "music book", "book" }));
		set("long", longs[num]);
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"music",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 10, 	// jing cost every time study this
			"difficulty":	24,	// the base int to learn this skill
			"max_skill":	50,	// the maximum level you can learn
		]) );
	}
}
