// Code of ShenZhou
// room: /mingjiao/suibei.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "�汱ɽ");
        set("long", @LONG
����������ܣ����������ƺ���δ�����߹����㴩����ɽ������֮
�У����߼�Ϊ���ѡ����в�ʱ�����Ź����Х�������˲�����������˵��
ɽ�����ޣ��粻�ǵ���ʮ�㣬��û���ԭ·���ذɡ�
LONG );

        set("exits", ([
                "southdown" : __DIR__"yushuquan",
                "north" : __DIR__"moli",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}