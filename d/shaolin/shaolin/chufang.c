// Code of ShenZhou
// Room: /d/shaolin/chufang.c
// Date: YZC 96/01/19
// modified by xiaojian on Aug.20,2000
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ƣ��������ڣ���ζ�˱Ƕ�������ǽ��һ�����ɳ���
��̨��֧��ʮ���ڴ��������һ�ڷ����Ϸ������˴���������
���£��ֳ�ľ���ڽ��衣�����շ���ɮ���⣬��λ��ͷ��æ��
������н������¯�����ܡ�һλ����ɮ�������شߴ��š�
LONG
        );

        set("exits", ([
                "south" : __DIR__"fanting1",
				"north" : __DIR__"houyuan",
        ]));
        set("objects",([
                __DIR__"npc/shaofan-seng" : 1,
        ]));
        set("cost", 0);
        setup();
        replace_program(ROOM);
}

