// Code of ShenZhou
// Room: /d/murong/qing4
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
    ��������Ľ�����µ���ר�õĻ������Ľ�����ȱ�Ϊ�������
�����������²������ˡ�����������Ľ������켣������������֮��
δ�����µ���ҲƵƵ�����ڽ�����
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing3",
        "north" : __DIR__"qing5",
                      ]));
	set("no_clean_up", 0);
        set("valid_startroom",1);
       
        set("objects", ([
		"/kungfu/class/murong/baichuan" : 1,
		]));

	setup();

        "/clone/board/murong_b"->foo();
}
