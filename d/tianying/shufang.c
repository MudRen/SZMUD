// Code of ShenZhou
// room: shufang.c

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
������ӥ�̵��鷿����ǽ�ڷ���һ����ܣ���������������Ÿ�
���鼮������������һ��īɫС�������ϵ���¯ð���������̣���ǰ
�и����ſɹ�����������������֮��������
LONG );

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        setup();
        replace_program(ROOM);
}
