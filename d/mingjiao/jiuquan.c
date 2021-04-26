// Code of ShenZhou
// room: /mingjiao/jiuquan.c

inherit ROOM;

void create()
{
        set("short", "��Ȫɽ");
        set("long", @LONG
��ɽ��ʮ��ƫƧ��ȴ����������ֻ��ɽɫ��䣬һ����Ȫ��ʯ����ӿ
�������겻�ݡ���Ȫˮ����������Ϊ�������Ƶ�����֮ѡ��������Ȫ����
��ɽ�������������࣬��Ȫˮ����ɽ��װͰ���ۣ���˵�۸񲻷ơ�
LONG );
        set("exits", ([
                "southdown" : __DIR__"luobuyi",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("resource/water", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}