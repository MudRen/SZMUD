// Code of ShenZhou
// room: zoulang2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵı���ͨ������
̳���ϱ�������̳��
LONG );

        set("exits", ([
                "north" : __DIR__"qinglongtan",
                "south" : __DIR__"xuanwutan",
		"east" : __DIR__"zoulang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
