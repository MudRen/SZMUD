// Code of ShenZhou
// By FunBoo@sz
inherit ROOM; 

void create() 
{ 
set("short", "办公室"); 
set("long", @LONG 
这里是ＧＡＴＥＯＰＥＮ的办公室。
LONG 
); 
call_other( "/clone/board/gateopen", "???" );
replace_program(ROOM); 
setup(); 
}
