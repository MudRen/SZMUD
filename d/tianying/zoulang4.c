// Code of ShenZhou
// room: zoulang4.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵı����ǰ׻�̳
���ϱ�����ȸ̳��
LONG );

        set("exits", ([
                "north" : __DIR__"baihutan",
                "south" : __DIR__"zhuquetan",
		"west" : __DIR__"zoulang3",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
