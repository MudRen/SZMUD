// Code of ShenZhou
// Room: baihe.c

inherit ROOM;

void create()
{
	set("short", "�׺�");
	set("long", @LONG
�����ǳ���ɽ�µ�һ��С�壬ֻ���ģ�����ª��Сľ�ݡ����ﲢû��
�̶��ľ���ľ�ݶ��ǽ�ɽ�ɲεĲο����ǣ�Ϊ�����ڽ�ɽǰ��������ú�
����Ϣһ�¡��������Ρ�������ĳ��״�ɽ��
LONG	);
	set("exits", ([ 
              "west" : __DIR__"gucd",
              "east" : __DIR__"milin1",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}
