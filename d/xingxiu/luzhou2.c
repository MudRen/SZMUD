// Code of ShenZhou
// luzhou.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "����");
	set("long", @LONG
������ݽϱ���Ϊ�࣬��ɳĮ�е�һ��ɽ´���ޣ�����������
ˮ����һ��СϪˮ����ף�Ϫˮ������С���������ײ����������
���������������ˣ��������֡�������ҫ֮�У����������л���Ʈ
����Ϫˮ���㣬���������л�֮�ʡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaoxi",
		"north" : __DIR__"shaqiu",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

