#include <ansi.h>
inherit ROOM;
void create()
{	set("short",GRN"酒馆"NOR);
	set("long",@LONG
这里是家具铺楼上附设的小酒馆。家具可都是一些大家伙，而且这里
都是一些大户人家，即便是三五个大汉也要忙忙碌碌地搬运几个来回，所
以自然需要这样一个休息聊天的地方。
    神州大街的住户也常在这个小酒馆里聊天聚会。
LONG	);
	set("exits",([
	"up" : __DIR__"shop",
	]));
	set("objects",([
	__DIR__"npc/waitress":1,
//	__DIR__"npc/obj/kalaok":1,
	__DIR__"npc/obj/table":1,
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",-10);
	set("no_fight",1);
	setup();
}
int valid_leave(object me, string dir)
{ object ob,*user;
  int i,j;
  if(!objectp(ob=present("bar waitress",this_object()))) return 1;
  if(ob->query("cost")==0) return 1;
  user=all_inventory(this_object());
  for(i=0;i<sizeof(user);i++) if(userp(user[i])) j++;
  if(random(j)>2) return 1;
  message_vision("$N微笑着说道：您还没付账呢。\n啊，",ob);
return 0;}
   