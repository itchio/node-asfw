{
    "targets": [
        {
            "target_name": "node_asfw",
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ],
            "sources": [ "addon.cc", "node_asfw.cc" ],
        }
    ]
}