// Code of ShenZhou
// liangongfang.c ������
// by Xiang
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ���λ�䵱��������ϥ������
�������
LONG
	);
	set("exits", ([
		"south" : __DIR__"donglang1",
	]));
	set("objects", ([
                "/d/huashan/obj/duanjian" : 1,
                "/d/huashan/obj/changjian" : 1,
                "/d/village/obj/zhujian" : 2]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
        }
        
        if ( j == 1 ) me->set_temp("marks/��", 1);
        if ( j > 1 ) return notify_fail("����ô��˽���㲻�ܴ��߳���һ�ѱ�����\n");

        return ::valid_leave(me, dir);
}
