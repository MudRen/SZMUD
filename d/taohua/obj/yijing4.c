// Code of ShenZhou
// yijing.c

inherit ITEM;

void create()
{
	set_name( "�׾���ϵ��ƪ��", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���׾�������д�ţ�\n
��������ر���Ǭ�����ӡ������Գ£����λ�ӡ� �����г���������ӡ�
������ۣ�����Ⱥ�֣��������ӡ� ��������ڵس��Σ��仯���ӡ�

������֮����������֮�Է��꣬�������У�һ��һ�Ǭ�����У�������
Ů��

����Ǭ֪��ʼ���������

����Ǭ����֪�����Լ��ܡ�

    ������֪�������״ӡ� ��֪�����ף��״����й��� ������ɾã���
����ɴ� �ɾ�������֮�£��ɴ�������֮ҵ��

    �׼򣬶�������֮���ӣ�����֮��ã�����λ�������ӡ�
\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 25, 	// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	120,	// the maximum level you can learn
		]) );
	}
}
