// Code of ShenZhou
// room: /mingjiao/yinan.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
��ɽ������������Ұʮ�ֿ�����ȴֻ����ɳ�������������̡���Хһ
��������ֻ�м����ӥ঻�Ӧ��ʹ�����в���ӿ��������į�¶��ĸо���
LONG );

        set("exits", ([
                "northdown" : __DIR__"yushuquan",
                "southeast" : __DIR__"douxian",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}

