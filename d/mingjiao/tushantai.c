// Code of ShenZhou
// room: /mingjiao/tushantai.c

inherit ROOM;

void create()
{
        set("short", "��ɽ̨");
        set("long", @LONG
�����ɽ�䣬�������������̨���е��Ѿ���ȱ����������̮���˰�
�ߡ�����������ʢ֮ʱ���˵ؾ�����פ�����أ������ǽ�������ˡ�����
��ʱ���������ص����ƣ�����ë���Ȼ��
LONG );

        set("exits", ([
                "southup" : __DIR__"monan",
                "north" : __DIR__"yinshandao",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}