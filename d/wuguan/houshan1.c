//Cracked by snso k1-7-6
// Room: houshan1.c ��ɽ

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "��ɽ");
    set("long", @LONG
���������ݵĺ�ɽ�ˣ�ɽ��������ľïʢ�����������������һ��
������Ȼ�ľ����峺��Ϫ����������һ��Сͤ�ӣ�����Ϫˮ��������ȥ
������ɽ�����������ԣ����ϴӶ��ߺ�Х�������Ӹ����£���Ŀ��������
��Զ������˷�������ɽ�����ơ�
LONG
    );

    set("exits", ([
	"southwest" : __DIR__"xiaolu1",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
       set("no_fight", 1);
       set("no_steal", 1);
       set("no_hit", 1);
    setup();
    //replace_program(ROOM);
}

