// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���磬������Զ����ͨ��˹���ϵ����ã��������ء�����������
��������ͨ��Ҫ�壬��˿��֮·����Ҫ����վ֮һ�������������̶�
������ʹ�ߣ��ڷ������׶���ԭ֮�ᣬҪ�������Ϣ�ͷַ������
ȥ�����ã��ڱ��������Ź����ɳ֮���ᣬ���˵�����������⣬��
Ҫ���÷�Խ���׶���ԭ�ŵ�������ɽ�ڵ�׼����
LONG
	);
	set("exits", ([
                "north" : __DIR__"beijiang",
                "south" : __DIR__"nanmen",
		"west" : __DIR__"majiu",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
