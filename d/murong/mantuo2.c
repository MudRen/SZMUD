// Code of ShenZhou
// Room: /d/murong/mantuo2
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
    ������ֲ��ɽ���ƽƽ���棬Ψһ�ĺô�ֻ�ǵø����ࡱ
�֡���ǰ����ɽ��Ʒ�ֽ��࣬ż��Ҳ��һ�������㲻��ȴ
Ҳ���ֲ����䷨��
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"mantuo3",
        "north" : __DIR__"mantuo1",
        "west" : __DIR__"huac1",
                      ]));
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}

