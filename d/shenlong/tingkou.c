// Code of ShenZhou
// ������ /d/shenlong/datingkou
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǵ������ſڣ����ڿɽ��������̵Ĵ������ſ�վ����������̵Ľ�ͽ��
ȫ����װ�������ע�����ܣ���������ϡ����һ�������������ƺ���������
�ٿ�ʲô��Ҫ���顣
LONG
	);

	set("valid_startroom",1);
	set("exits", ([
		"enter" : __DIR__"dating",
                "west" : __DIR__"changlang",
	]));

	set("objects", ([
          //      "/kungfu/class/shenlong/heilong" : 1,
                "/d/shenlong/npc/hei" : 1,
                "/d/shenlong/npc/chi" : 1,
          //      "/kungfu/class/shenlong/dengbing" : 1,
	]));
	set("cost", 1);

	set("no_clean_up",0);
	setup();
	"/clone/board/shenlong_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping myfam = (mapping)me->query("family");
        object *inv;
        int haveguarder;

	if( !(me->query("sg/spy") || me->query("family/family_name") == "������") && dir == "enter" ) {
                inv = all_inventory(this_object());
                for(int i = 0; i < sizeof(inv); i++ )
                        if( inv[i]->query("family/family_name") == "������" || inv[i]->query("sg/spy") ) {
                                 haveguarder++;
                                 if( living(inv[i]) ) inv[i]->kill_ob(me);
                        }

                if( haveguarder > 0 )
		        return notify_fail("��Ҳ̫Ŀ�������˰ɣ���������������ء�\n");
         }

	 return ::valid_leave(me, dir);
}

