// Code of ShenZhou
// room: fanting.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ӥ�̵ķ�����һ���ŵ����ӵ�������İ����������
һ����Ĵ�����ʹ�㲻�������³Ե�ʲô���������ں��žƣ�����ߺ
���ţ������ڲ�ȭ��
LONG );

        set("exits", ([
                "south" : __DIR__"lianwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
