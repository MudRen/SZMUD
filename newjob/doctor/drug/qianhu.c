#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( WHT "前胡" NOR , ({"qian hu", "hu"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "前胡：根茎类，苦，微寒。李时珍认为：前胡味甘辛，气微平，其功长于下气，故能治痰热、喘嗽、痞膈、呕逆诸疾。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",10);
        }
        setup();
}
