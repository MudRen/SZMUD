// Code of ShenZhou
// Room: /d/mingjiao/luanshidui.c
#include <ansi.h>
inherit ROOM;

void set_randomroom();
void out_player(object ob);
void create()
{
	
	set("short", "��ʯ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);


	set("no_clean_up", 0);
	setup();
	set_randomroom();
	
}

void init ()
{
//	object ob;
	//if (interactive(ob = this_player())) 
//		remove_call_out("out_player");
//		call_out("out_player", 5, ob);
	

}
//��ȥʱ����ȥ������ĳɹ�
void out_player(object ob)
{
	string file_name,file_end;
	file_end=file_name(environment(ob));

	file_name = implode(explode(file_end, "/")[0..<2], "/");
	if (!ob->is_busy())
	if(file_name=="d/mingjiao/tiekuangshan"||file_end="d/mingjiao/tiekuang")
	{
		tell_object(ob,HIW"\n\n��ֱ����ǰ��ʯ���ݺύ��������������������ںδ���ֻ����ԭ·�˻ء�\n\n"NOR);
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
	if(file_name=="d/mingjiao/tiekuangshan"||file_end="d/mingjiao/tiekuang")
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
	call_out("set_randomroom", 700);
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
				 call_out("out_player", 600, ob);
				 remove_call_out("out_message");
				 call_out("out_message", 300, ob);
	 }
        return ::valid_leave(ob, dir);
}

