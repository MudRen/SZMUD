// Code of ShenZhou
// huayanding.c ���϶�
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "���϶�");
        set("long", @LONG
���϶�ͦ�θ��ͣ���ɲ���������ʣ��羰���ա�������Ұ����������
����ΡΡ��������Ⱥ�����У����׷�ɽ�����ԺҲ���۵ס��ɴ���������
�£���������ʯ�����¹�ʮ���̿ɵ������¡�������һ����ǡ�
LONG
        );
        set("exits", ([
                "westup" : __DIR__"lianhua",
		"down" : __DIR__"pan12",
		"north" : __DIR__"majiu2",
        ]));

        set("objects",([
                __DIR__"npc/f_dizi1" : 1,
                CLASS_D("emei") + "/li" : 1,
        ]));

        set("no_clean_up", 0);

        set("fjing", 1);
        set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
