//Cracked by snso k1-7-6
// Room: huayuan.c ��԰

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "��԰");
    set("long", @LONG
������ݵĺ�԰��ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾��
�������壬���ɴ��񣬾���ɷ�����ˡ�����������ȥ���Ǻ�ɽ�ˡ�
LONG
    );

    set("exits", ([
	"south" : __DIR__"kaojiao",
	"northeast" : __DIR__"houshan1",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
       set("no_fight", 1);
       set("no_steal", 1);
       set("no_hit", 1);
    setup();
    //replace_program(ROOM);
}
