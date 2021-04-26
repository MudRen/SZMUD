// Code of ShenZhou
// Room: /shguan2.c


inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
����ͷ�����ﳤ����ˡ��κ�¥Ρ��߾��ͷ��¥�ϡ��۽������
���ҾӸ����£�ֱ���󺣡��Գκ�¥����һʯ���𼶶�������󺣣�վ��ʯ
���ն�¥ƽ̨������������һɫ���ޱ��޼ʣ�������ǧ��
LONG
	);

	
	set("exits", ([
		"northwest" : __DIR__"shguan1",
                "south" : "/d/beijing/yidao3",
	]));

        set("objects",([
                 __DIR__"npc/feng" : 1,
        ]));
        
	set("outdoors", "changbai");
        set("cost", 3);

	setup();
        replace_program(ROOM);
}


