// Code of ShenZhou
// changle/clbajiaoting.c
// by aln 2 / 98
// xQin 8/00

inherit ROOM;

void create()
{
        set("short", "�˽�ͤ");
        set("long", @LONG
���ǻ�԰��һ��С�ɵ�ͤ�ӣ����ͻ�ʱ��Ϣ֮�á�ͤ��ʯ��ʯ��
��ȫ��ʯ���ϻ��ڷ��ż��̵��ġ�Ժ�л��ܰ��㸡����������ɽ����
���Ǳ��¡�
LONG );

        set("exits", ([
		"north" : __DIR__"clhuayuan",
		"west" :  __DIR__"clzoulang1",
        ]));
        
        set("cost", 0);

        setup();

        replace_program(ROOM);
}
