/*-------------------------------------------------------------
** �ļ���: qingjiaoshi.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: �����
**-----------------------------------------------------------*/


inherit ROOM;

void create()
{
        set("short","�����");

        set("long",@LONG
����һ��ʮ�ִ�����ӣ��������м������ӣ���ݵļ�λ��ͷ������
�����ݵ���ָ����ֻ���������书��
LONG);

         set("exits", ([ 
                "southwest" : __DIR__"zoulang1",
                 ]));

 	set("objects", ([
		__DIR__"npc/longquan" : 1,
		__DIR__"npc/liuhongying" : 1,
	]));

          
        set("cost",0);
        set("no_steal", 1);
        set("no_hit", 1);

     setup();
}

