//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������С������֮�����ڣ�������̨������������������������ǰ
����о�����̬���죬�������������е��������񡣱ڶ���Ϊ���º�ˮ��
���ն����������Σ�����Ϊ���º�ˮ�����µ����������Ρ�Ӱ�����İٶ�
ʮ�Ŀ���ɫ����ש�������ɡ�ɫ��Ѥ�������Ӵ󷽡�
LONG
	);
	set("cost", 2);
    
	set("exits", ([
                "south" : __DIR__"dukou1",
                "east" : __DIR__"xitian",
        ]));
	
	
	setup();
	replace_program(ROOM);
}