// Code of ShenZhou
// room: /mingjiao/douxian.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
������ɽ�������ۣ����ƹ���һ�����䡣ɽ·��Ҳƽ̹��Ȼ��ɽ��Ұ
�����������ߵͰ���ԡ���Щ��������С�̣�����С�ı�Ữ����Ѫ���졣
LONG );

        set("exits", ([
                "eastdown" : __DIR__"longquangu",
                "northwest" : __DIR__"yinan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}