// Code of ShenZhou
// Room: /d/shaolin/jianyu.c
// Date: lisser 2001/10/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ
���Կ�������ƺ��м�����Ӱ��������ת��ͷȥ������������ס
���������ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ���
���ɣ�ֻ�б�����һ��С�ţ����Ͽ��˸����ƴ�Ķ��������ͷ�
�õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��һ��
�׵÷����Ŀݹǡ�
LONG
	);

        set("no_fight",1);
        set("no_get",1);
	set("valid_startroom",1);
	set("cost", 1);
	setup();

}
void reset()//make this room no refresh
{
        ::reset();
        set("no_clean_up", 1);
}
void init()
{       
	object ob = this_player();

        add_action("do_practice", "sleep");
        add_action("do_practice", "xiulian");
        add_action("do_practice", "lianneili");
        add_action("do_practice", "lianqi");

        if( (int)ob->query_condition("expell_c") <= 0 && !wizardp(ob))
	{
		message("vision",
			HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n" NOR, 
			environment(ob), ob);
		ob->set("startroom", "/d/taishan/jianyu");
                ob->apply_condition("expell_c", 960);
		ob->unconcious();
	}
}
int do_practice()

{
        write("Ъ����ɣ���\n");
        return 1;
}
