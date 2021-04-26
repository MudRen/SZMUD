// Code of ShenZhou
// wuji2.c

inherit ITEM;

string* titles = ({
        "����ǧҶ���ַ�",
        "����ȭ��",
        "�޳��ȷ�",
        "�ȱ�����",
        "���޵���",
        "�������",
});

string* skills = ({
        "qianye-shou",
        "jingang-quan",
        "wuchang-zhang",
        "cibei-dao",
        "xiuluo-dao",
        "zui-gun",
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
	set("value", 200);
	set("material", "paper");
	set("skill", ([
			"name":	skills[i],	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost": 40,// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	299	// the maximum level you can learn
		      ]) );
}
