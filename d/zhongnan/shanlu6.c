// Code of ShenZhou
// road: /zhongnan/shanlu6.c

inherit ROOM;

void create()
{
        set("short","ɽ·");

        set("long",@LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�����
�Ű�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��
ع�㣬���������֦ͷ�����䳪�������������ǲ����¡���������һ��ɽ
·��������һ����Ŀյء�������ͨ����ɽ�¡�
LONG);

		  set("exits",([
								"westup" : __DIR__"shanlu7",
								"northwest" : __DIR__"shanlu13",
								"northdown" : __DIR__"xiaosi",
								"eastdown" : __DIR__"dajiaochang",
				])
           );
	  set("cost",3);
	  set("outdoors", "zhongnan");

        setup();


        replace_program(ROOM);
}
