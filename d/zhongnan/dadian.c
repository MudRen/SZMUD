// Code of ShenZhou
// road: /zhongnan/dadian.c

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short", HIR"������������"NOR);

		  set("long",@LONG
�������ȫ���λ�����ɽ���ܲ���������ֻ������������
������ɽ´�������ݶ�����ɫ�����ߣ��������ŷ������ޣ�������������
����ǽ�����ʮ�־����������ṹ�쳣�Ͻ����������Ƹ߹ң���ᣵʹ���
�����������������ǽ�Ϲ���һ������(hua)����������һ���㳡��������
�ĵ�����һ���ȡ����������������������ͨ�����ĵ
LONG);

	  set("item_desc",(["hua" : "
�⻭����һ��������ߵ�������ˣ�ü�������һ��Ӣ��������ֻ��
������������һϮ�������ڷ�������Ʈ�����ľ��ɷ����֮��������Ϊ֮
���ۡ�\n",]));

        set("objects", ([
					 //CLASS_D("quanzhen") + "/qiu" : 1,
                "/clone/npc/qiu":1,
					 ]));

		  set("exits",([
								"west" : __DIR__"zhoulang",
								"north" : __DIR__"taijie2",
								"northeast" : __DIR__"yuanneixiaojing1",
								"southdown" : __DIR__"guangchang",
							 ])
			  );
		  set("cost",1);

		  setup();

	//"/clone/board/quanzhen_b"->foo();
}
