//Cracked by snso k1-8-5-6
// Room: zoulang4.c ���� 4

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "����");
    set("long", @LONG
�ߵ�������پ��ÿ��˺ܶ࣬��ס�������������������������߾͵���
��������ң��������������д��书���Թ����ˡ�
LONG
    );                                                                                         

    set("exits", ([
	"north" : __DIR__"houting",
	"southeast" : __DIR__"shigong",
//	"west" : __DIR__"renwu",
    ]));
      set("no_fight", 1);
      set("no_clean_up", 0);
      set("cost", 1);
    setup();
    //replace_program(ROOM);
}
