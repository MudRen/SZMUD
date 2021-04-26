// Code of ShenZhou
// Room: /d/mingjiao/luanshidui.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

void set_randomroom();
void out_player(object ob);
void create()
{
	
	set("short", "��ʯ��");
	set("long", @LONG
�˴���ʯ����������ȥ���»���·������Ҳûʲô������ľ��һЩ
���ι�״�Ĵ�ʯͷ�Ҷ����ԡ�
LONG
	);
	set("no_clean_up", 0);
	set("cost", 5);
	setup();
	set_randomroom();
	
}

void init ()
{
/*	object ob;
	if (interactive(ob = this_player())) 
		remove_call_out("out_player");
		call_out("out_player", 150, ob);
	
*/
}
//��ȥʱ����ȥ������ĳɹ�
void out_player(object ob)
{
	string file_name,file_end;
	file_end=file_name(environment(ob));

	file_name = implode(explode(file_end, "/")[0..<2], "/");
	if (!ob->is_busy())
	if(file_name=="d/mingjiao/tiekuangshan"||file_end=="d/mingjiao/tiekuang")
	{
		tell_object(ob,HIW"\n\n��ֻ����ǰ��ʯ���ݺύ��������������������ںδ���ֻ����ԭ·�˻ء�\n\n"NOR);
		ob->move("/d/mingjiao/luanshidui");
		return;
	}
	remove_call_out("out_player");
	call_out("out_player", 1, ob);
	return;

}

void out_message(object ob)
{	
	string file_name,file_end;
	file_end=file_name(environment(ob));

	file_name = implode(explode(file_end, "/")[0..<2], "/");
	if(file_name=="d/mingjiao/tiekuangshan"||file_end=="d/mingjiao/tiekuang")
		tell_object(ob,HIW"\n\n��ֻ����ǰ��ʯ���ݺύ���Ѿ��쿴��������ںδ�����֪������Ͽ��߳�����ʯ���󣬱�Ȼ���Ĳ��ס�\n\n"NOR);

	return;

}

void set_randomroom()
{
	object room;
	delete("exits");
	set("exits", ([ 
	 "northeast" : __DIR__"shanlu23",
	 ]));

	room=new("/clone/room/randomroom");
	room->Set_Room(1,4,"/d/mingjiao/luanshidui","/d/mingjiao/tiekuangshan/","/d/mingjiao/tiekuang",0);
	call_out("set_randomroom", 300);
}

int valid_leave(object ob,string dir)
{
	int i;
	object obj, *inv;
	 if (dir != "northeast") 	
	 {
		 inv = deep_inventory(ob);
		 if(sizeof(inv))
			 for(i=0; i<sizeof(inv); i++) 
				 if(userp(inv[i])) 
					 return notify_fail("��ֻ��ǰ����ʯ���ݺύ��ʵ��˵������Σ�ա����������ϱ��ű��ˣ���θ���ǰ�ߡ�\n");

				 remove_call_out("out_player");
				 call_out("out_player", 200, ob);
				 remove_call_out("out_message");
				 call_out("out_message", 100, ob);
	 }
	 else
	 {
		  remove_call_out("out_player");
		  remove_call_out("out_message");
	 }
        return ::valid_leave(ob, dir);
}

