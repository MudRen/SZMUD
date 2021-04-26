#include <ansi.h>
inherit ITEM;
void create()
{	set_name("卡拉ｏｋ",({"kala ok","singer"}));
	set("long","一部卡拉ｏｋ机。大屏幕彩电，超震撼音响。不来一曲？(sing)\n");
	set("unit","部");
	set("value",99);
	set("no_get",1);
}
void init()
{	add_action("do_sing","sing");
}

int do_sing(string arg)
{ string msg;
  string *color=({HIR,HIG,HIY,HIB,HIM,HIC,HIW});
  string *word=({

"村里有个姑娘。。。",
"啦~~~~~呀~~啦~~~~~~"});
  string *verb=({

"拉着嗓子五音不全地唱到：",
"扯着破铜锣嗓子吼着：",
"甜腻兮兮地柔声唱到："});
  string *eff=({

"（不要嘘，不要嘘。）",
"（哇，吵死了！）",
"（唱的多好啊，鼓掌。）"});
  object me=this_player();
  msg=color[random(sizeof(color))]+"$N"+verb[random(sizeof(verb))];
  if(arg) msg+=arg;
  else msg+=word[random(sizeof(word))];
  if(random(20)<5) msg+=eff[random(sizeof(eff))];  
  message_vision(msg+NOR"\n",me);
return 1;
}
