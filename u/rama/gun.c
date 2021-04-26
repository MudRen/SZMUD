inherit F_CLEAN_UP;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("激光枪", ({ "gun" }) );
        set("long", "……。\n");
        set_weight(100);
        set_max_encumbrance(100000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material", "steel");
                set("value", "100");
                }
        set("no_get", 1);
        set("no_steal", 1);
        enable_commands();

        setup();
}
void init()
{
        add_action("do_destroy","shoot");
}
        


int do_destroy(string arg)
{
                 object obj,me;
                 me=this_player();

                 if(me->query("id")!="rama")
                  return notify_fail("什么？\n");

                 if (!arg) return notify_fail("指令格式：destroy object.\n");

                 if(!objectp(obj = present(arg, environment(this_player()))))
                                         return notify_fail("这里没有这个人。\n");                
                                         if (!obj) obj = present(arg, me);               
                                         if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );             
                                         if (!obj) return notify_fail("没有这样物件....。\n");                   
                                         message_vision(CYN"$N掏出一把激光枪，对准$n嘭的开了一枪，把$p打成一片硝烟消失了！”\n"NOR,me,obj);
                                         seteuid(ROOT_UID);              
                                         destruct(obj);                  
                                         if(obj){ write("你无法将这个物件摧毁。\n"); 
                                         return;}                   
                                         return 1; } 


