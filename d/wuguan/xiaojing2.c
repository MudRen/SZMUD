/*-------------------------------------------------------------
** �ļ���: xiaolu1.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ��ɽС��
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","��ɽС��");

        set("long",@LONG
����һ��ͨ����ɽ����ּ�С·����Χ����໨�ݺ���ľ��������
�ߺ�����һ���ͱڡ�
LONG);

         set("exits",([ 
                "west" : __DIR__"cliff1",
                "east" : __DIR__"xiaojing1",
                 ]));

         set("outdoors", "wuguan" );
         set("cost", 1);
	 set("no_fight", 1);
         set("no_steal", 1);
         set("no_hit", 1);
     setup();
     }