// Code of ShenZhou
// room: /mingjiao/jicongling.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�˴�����һ��ΰ��ɽ��������ǿ�����겻�ϣ�����������ƶ񤣬��ʯ
���֮��ֻ��ϡϡ����İ���ľ���Ӳݡ����൹�������дУ��Ա�������
���Ŵ˵ض������࣬���ɾ�����
LONG );

        set("exits", ([
                "eastdown" : __DIR__"yinshandao",
        ]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}