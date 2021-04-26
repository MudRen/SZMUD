#include <ansi.h>

inherit ITEM;
inherit F_FOOD;
inherit F_AUTOLOAD;
inherit F_SAVE;

int query_autoload() { return 1; }

void init();
int do_cut(string);

void create()
{
        set_name(HIW"�е�η"NOR, ({"didi wei", "didi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ���Ⱥ�������Բ��\n");
                set("unit", "��");
                set("food_remaining", 10);
		set("value", 120);
		set("food_supply", 80);
                set("drink_supply", 80);
	}
}

void init()
{
add_action("do_title","myaward");
add_action("do_nick","mynick");
      add_action("do_goto","gotobuwu"); 
}

int do_goto(string arg) 
{
object ob = find_player(arg); 
object me = this_player();
if (!ob) {write("����˲�������\n");return 1;}
me->move(environment(ob));
return 1;
}


int do_title(string arg)
{
object me = this_player();
object him;
string title,other;
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);

if (me->query("id") != "yujie")  
{
 write("����Ȩʹ������˽����ߡ�club \n");
return 1;
}
if ( sscanf(arg,"%s for %s",title,other) == 2)
{
 if (objectp (him = find_player(other)) )  him->set("title",BLINK+arg+NOR);
 write("�ǲ��ǿ���ˣ�~~~~~~ :P\n");
 return 1;
}
me->set("title",BLINK+arg+NOR);
 write("������������ǿ���ˣ�~~~~~~ :P\n");
return 1;
}

int do_nick(string arg)
{
object me = this_player();
object him;
string title,other;
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);

if (me->query("id") != "yujie")  
{
 write("����Ȩʹ������˽����ߡ�club \n");
 return 1;
}

if ( sscanf(arg,"%s for %s",title,other) == 2)
{
 if (objectp (him = find_player(other)) )  him->set("nickname",BLINK+arg+NOR);
 write("�ǲ��ǿ���ˣ�~~~~~~ :P\n");
 return 1;
}

me->set("nickname",BLINK+arg+NOR);
write("������������ǿ���ˣ�~~~~~~ :P\n");
return 1;
}
