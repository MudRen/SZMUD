// Code of ShenZhou
//GU MU FROM SANTA
//houtang.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ������Ҳ�ǿյ�����û������裬ֻ�ж������ڶ�����һ������
���ڻ�(hua1)������������������������Ļ���(hua2)��һλ��
��.
LONG
	);

	set("item_desc", ([
	"hua1" : "\n
ֻ�������������һ����ʮ�����꣬���ڶԾ���װ����һ����
ʮ�������Ѿ�ߣ��������裬�����̺򡣻��о���ӳ�����곤Ů����
ò��������ü���ޣ��۽�֮��ȴ��������һ��ɱ���������˼��ۣ���
�²��Խ��Ĵ�����η֮�

	"hua2" : "\n
�����������ߣ�����ʳָָ�������ǣ�ֻ�Ǳ������⣬��òȴ
��������������Լ�ɼ�̵��.
	]));

	 set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east" : __DIR__"shufang",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
